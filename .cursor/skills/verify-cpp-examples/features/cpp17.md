# C++17 demonstrations
## Sub-features
Optional remains unconstructed until assignment, variant stores int/double, parser extracts URL fields.
## How to get to it (user POV)
Compile c++17/optional.cpp, variant.cpp or parse_url_std_optional.cpp separately with -std=c++17 and run.
## Driving it with drive.py
Run drive. Exact optional and variant stdout and zero exits are checked. Parser's existing asserts validate two URLs and their fields.
## Gotchas
No malformed URL or large port test is included. Many remaining C++17 files are outside this seed. Assertions must stay enabled, not -DNDEBUG.
