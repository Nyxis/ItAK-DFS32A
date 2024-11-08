# C development with vscode and remote container

## Prerequisites:

* Docker installed
* VSCode with [remote container extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

## Getting started

1. Clone this project
2. Open it with VSCode

If prompted, accept the "Reopen folder to develop in container" notification. If not:

1. Run the command: `Remote-containers: Open folder in container...`
2. Pick this folder as your root project
3. Default from .devcontainer/devcontainer.json should be enough to dive in coding, but feel free to customize it

## Start coding

Try to compile and run the code example:
1. Run the command `Terminal: Create New Integrated Terminal` if no terminal was opened
2. Run in shell `gcc -o binary main.c && ./binary`
3. You should see "Hello world!" in your terminal as a result
4. Enjoy
