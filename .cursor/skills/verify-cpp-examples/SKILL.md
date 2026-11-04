---
name: verify-cpp-examples
description: Compile and run actual independent C++ learning examples in cpp_adventures before changes to algorithms or C++17 demonstrations.
---
# Verify C++ examples

## Surface and isolation
This is a source-example collection, not one app. Each selected file is an independent short-lived CLI. Qt, CUDA, Boost, ZeroMQ, benchmarks, filesystem and network examples are separate surfaces and are not covered by the safe default drive. Never compile every source into one executable. No credentials, external services or shared instances are needed for this drive.

## Launch
Install Python3 and a C++17-capable g++ compiler. From the repository root run:
`python3 .cursor/skills/verify-cpp-examples/helpers/drive.py doctor --out .verification-evidence/doctor`
Ready means g++ responds and the expected algorithm source exists. Compilation happens per journey in a fresh temporary directory.

## Doctor
The command above checks compiler identity and repository root without running product examples. Run it before a drive or after a surprising failure.

## Drive
`python3 .cursor/skills/verify-cpp-examples/helpers/drive.py drive --out .verification-evidence/run`
The helper compiles six actual example executables, checks their exact stdout and exit status, then compiles the actual binary-search function with a renamed demonstration main and tests five boundary cases. Each process has a15second timeout. This does not establish every file in this collection builds.

## Evidence
Retained doctor.json/drive.json records compiler commands, output, errors and exit codes. A contract mismatch or timeout exits nonzero. The URL parser's shipped assertions run with assertions enabled. Binary-search tests include left/right/middle, absent and empty ranges. No benchmark/performance claim is made.

## Cleanup
The helper waits for its child processes and removes only its own temporary build directory, including after failures. JSON evidence remains in the requested output directory. There is no server or shared data to stop. Never remove evidence during cleanup.

## Helpers
Executable helpers/drive.py provides doctor and drive commands above. See features/README.md for mapped and explicitly unverified areas. Keep the map current using maintain-verification-skill when source changes.
