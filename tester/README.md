# Cub3D_tester

## Description

These tests are created with certain textures and maps that you can find in the repository. The name of the test explains the test; if you are in need of more specific details, then check the args/map tested in the specific test.

All tests are tested with `valgrind`. 
For invalid maps it checks the `stderr` to have `Error\n` as the first thing, since that is what is required by the subject of the project.
For valid maps it checks whether the program returned `0`.

## Instructions
> If you are testing on 42 campus computers, Criterion is already installed there, no need to do anything extra.

First, you need to install the dependencies like `criterion`. Depending on your system:
- **Ubuntu/Debian**: `sudo apt install libcriterion-dev`
- **macOS**: `brew install criterion`

You can modify the name of the executable in `tests/tester.h` at `#define PROG "./cub3D"` with the correct path/executable name (in case you want to test the bonus, e.g., `./cub3D_bonus`).

The exit code of your program in case of errors has to be: 
- not zero(used for success)
- not 255(currently used by the tester for system related errors)
- not 42(used to detect valgrind errors)

## Execution

Go to your repository that contains `./cub3D` executable.

Clone this repo and compile the tester by running these commands:
```
git clone git@github.com:VestaManuyko/Cub3D_tester.git tester
cd tester
make
```
You can run all tests as:
```
./tester
```
or as:
```
make test
```
If you want separated output of valid and invalid tests run \
for valid:
```
make valid
```
for invalid:
```
make invalid
```

> Note: The tester assumes that hidden file with valid ".cub" extension are valid and that filename with spaces are allowed. \
> Since the subject doesnt specify they are up to you to handle, but make sure you can defend your desicion during the evaluation of the project.

Good luck with the project!