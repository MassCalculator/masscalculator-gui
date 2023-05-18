# Build the MassCalculator GUI

The MassCalculator GUI is built using CMake, therefore two steps are needed:

## CMake Configuration

Create a build directory, anywhere but inside the source directory.
Call CMake using the following commands:

### Basic Configuration, Debug, no Extra Tools, no Tests, no Documentation

```bash
cmake -S $MASSCALCULATOR_GUI_SOURCE -B <BUILD DIRECTORY>
```

### Configure Build with Doxygen Documentation

```bash
cmake -S $MASSCALCULATOR_GUI_SOURCE -B <BUILD DIRECTORY> -DBUILD_DOCS=ON
```

## Build

From the build directory call

### Build everything

```bash
cmake --build .
```

### Old way build

```bash
cd $MASSCALCULATOR_GUI_SOURCE
mkdir build && cd build
cmake .. -DBUILD_TESTS=ON 
cmake --build .
```

## Documentation

The Doxygen documentation will be available under the subdirectory `docs/html`
of your build directory. E.g., in `build/docs/html`.
