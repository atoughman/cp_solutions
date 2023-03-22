const fs = require("fs/promises");
const path = require("path");

const ignoreList = ["DS and Algo","contest-link.md"];

const countFiles = async (dir, ignoreList = []) => {
    let count = 0;
    const entries = await fs.readdir(dir);
    const files = entries.filter(
        (entry) => !ignoreList.includes(entry) && !entry.startsWith(".")
    );

    const set = new Set();
    for (const entry of files) {
        const entryPath = path.join(dir, entry);
        const stat = await fs.stat(entryPath);

        if (stat.isDirectory()) {
            count += await countFiles(entryPath, ignoreList);
        } else {
            const fileName = path.basename(entry, path.extname(entry));
            set.add(fileName);
        }
    }
    count += set.size;

    return count;
};

const countFilesInSubFolder = async (dir, ignoreList = []) => {
    let count = 0;
    const entries = await fs.readdir(dir);
    const files = entries.filter((entry) => {
        if (ignoreList.includes(entry)) {
            console.log("Ignoring ", entry);
        }
        if (entry.startsWith(".")) {
            console.log("Ignoring ", entry);
        }
        return !ignoreList.includes(entry) && !entry.startsWith(".");
    });

    // count only files in folders of current directory...
    const filesCount = {};
    for (const entry of files) {
        const entryPath = path.join(dir, entry);
        const stat = await fs.stat(entryPath);

        if (stat.isDirectory()) {
            const res = await countFiles(entryPath, ignoreList);
            filesCount[entry] = res;
            count += res;
        } else {
            console.log("Ignoring ", entry);
        }
    }
    console.log(filesCount);
    return filesCount;
};

async function main() {
    try {
        const filesCount = await countFilesInSubFolder("./", ignoreList);
        const totalFiles = Object.values(filesCount).reduce((a, b) => a + b, 0);
        console.log(`\nTotal number of files: ${totalFiles}\n`);
        
        const subfolderList = Object.entries(filesCount);

        // Sort subfolders by count of files
        subfolderList.sort((a, b) => b[1] - a[1]);

        // Generate badges for each subfolder
        const badges = subfolderList.map(
            (subfolder) =>
                `   <img src="https://img.shields.io/badge/${subfolder[0]}-${subfolder[1]}-brightgreen" alt="${subfolder[0]}" width="auto" height="30px">&nbsp;&nbsp;&nbsp;`
        );

        // Update the readme.md file with the badges
        const readmePath = path.join(__dirname, "readme.md");
        const readmeContent = await fs.readFile(readmePath, "utf-8");

        const startMarker = "<!-- Shields -->";
        const endMarker = "<!-- About -->";
        const startIndex = readmeContent.indexOf(startMarker);
        const endIndex = readmeContent.indexOf(endMarker);

        let newReadmeContent = readmeContent.replace(
            /Total Problems solved = \d+/,
            `Total Problems solved = ${totalFiles}`
        );

        newReadmeContent =
            newReadmeContent.slice(0, startIndex + startMarker.length) +
            `\n<div class="shields" style="display:flex">\n` +
            badges.join("\n") +
            `\n</div>\n` +
            newReadmeContent.slice(endIndex);

        await fs.writeFile(readmePath, newReadmeContent);
        console.log("Updated the readme.md file successfully.\n");
    } catch (error) {
        console.error(error);
    }
}

main();
