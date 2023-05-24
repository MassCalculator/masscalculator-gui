cmake_minimum_required(VERSION 3.15)

set(MASSCALCULATOR_CORE_REQUIRED_VERSION 0.1.0)

# Check that MassCalculator Core is installed in the system.
# This call cannot fail.
find_package(masscalculator-core ${MASSCALCULATOR_CORE_REQUIRED_VERSION} REQUIRED)
