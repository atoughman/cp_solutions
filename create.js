const fs = require('fs').promises;
const path = require('path')
const { exec } = require('child_process');

// polyfill for reading input from terminal
let rl = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout
})

let input = () => {
    return new Promise((resolve, reject) => {
        rl.question("", resolve)
    })
}

const colors = {
  FG_GREEN: "\x1b[32m",
  FG_RED: "\x1b[31m",
  FG_CYAN: "\x1b[36m",
  RESET: "\x1b[0m",
  bold: "\x1b[1m",
  FG_YELLOW: "\x1b[33m"
};


const SYMBOL_SUCCESS = "✔";
const SYMBOL_ERROR = "✖";

async function createFile(dirPath, fileName, sourceFilePath, url) {
  // Combine the directory path and file name to create the full file path
  const filePath = `${dirPath}/${fileName}`;

  try {
    // Check if the file already exists
    try {
      await fs.access(filePath);
      console.log(
        `\n${colors.bold}${colors.FG_RED}${SYMBOL_ERROR} File ${colors.RESET}${colors.FG_YELLOW}${fileName}${colors.bold}${colors.FG_RED} already exists in ${colors.RESET}${colors.FG_YELLOW}${dirPath}${colors.RESET}\n`
      );
      return;
    } catch (error) {
      // Ignore the error if the file doesn't exist
    }
  

    // Read the content of the source file
    const data = await fs.readFile(sourceFilePath, 'utf8');
    const lines = data.split('\n');

    // add problem URL
    lines[1] = `// ${url}`;
    const updatedContent = lines.join('\n');

    // Write the updated content to the new file
    await fs.writeFile(filePath, updatedContent);

    console.log(
      `\n${colors.bold}${colors.FG_GREEN}${SYMBOL_SUCCESS} ${colors.FG_CYAN}${fileName}${colors.RESET} ${colors.FG_YELLOW}File ${colors.FG_GREEN}Successfully created. ${colors.RESET}`
    );

    // open file in vs code
    console.log('\nOpening File in Vs Code.\n');
    exec(`code ${filePath}`);
    
    // run problem counter script
    console.log('Running Problem counter script.\n');
    exec(`node .\\problemSolvedCounter.js`)
  } catch (err) {
    console.log(`\n${colors.bold}${colors.FG_RED}${err.message}${colors.RESET}`);
  }
}

let create = async () => {
    const url = await input();
    const parts = url.split('/')

    const websiteName = parts[2];  // leetcode.com

    const websiteFolderMap = {
        'leetcode.com': 'Leetcode'
    }
    const FolderName = websiteFolderMap[websiteName]

    const problemNameIndex = parts.indexOf('problems') + 1;
    const fileName = parts.at(problemNameIndex) + '.cpp';  // 2-sum-calculate.cpp

    const currentDir = process.cwd();
    const resultFileDestination = path.join(currentDir, FolderName)
    
    const sourceFilePath = path.join(currentDir, 'template.cpp');

    await createFile(resultFileDestination, fileName, sourceFilePath, url)
}

create().finally(() => {
    rl.close();
})