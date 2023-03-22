const fs = require("fs/promises");
const path = require("path");

const ignoreList = [];

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
    const files = entries.filter(
        (entry) => {
            if(ignoreList.includes(entry)) {
                console.log("Ignoring ", entry);
            }
            if(entry.startsWith(".")) {
                console.log("Ignoring ", entry);
            }
            return !ignoreList.includes(entry) && !entry.startsWith(".")
        }
    );

    // count only files in folders of current directory...
    for (const entry of files) {
        const entryPath = path.join(dir, entry);
        const stat = await fs.stat(entryPath);

        if (stat.isDirectory()) {
            count += await countFiles(entryPath, ignoreList);
        }else {
            console.log("Ignoring ", entry);
        }
    }

    return count;
};

async function main() {
    try {
        const totalFiles = await countFilesInSubFolder("./", ignoreList);
        console.log(`Total number of files: ${totalFiles}`);

        // update the readme.md file with the total number of problems solved
        const readmePath = path.join(__dirname, "readme.md");
        const readmeContent = await fs.readFile(readmePath, "utf-8");
        const newReadmeContent = readmeContent.replace(
            /Total Problems solved = \d+/,
            `Total Problems solved = ${totalFiles}`
        );
        await fs.writeFile(readmePath, newReadmeContent);
        console.log("Updated the readme.md file successfully.");
    } catch (error) {
        console.error(error);
    }
}

main();
