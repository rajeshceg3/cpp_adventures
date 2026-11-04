# Other examples and coverage limits
## Sub-features
Concurrency, networking, filesystem, STL, Qt, CUDA, Boost, ZeroMQ and benchmark examples.
## How to get to it (user POV)
Read README categories and the relevant individual source. There is no single build target for the whole collection.
## Driving it with drive.py
Not driven by the safe default helper. Interview a specific source and establish its inputs, side effects, external prerequisites and cleanup before adding a journey. The helper deliberately does not invent behavior for these files.
## Gotchas
Qt/CUDA/Boost/ZeroMQ/benchmark dependencies are not installed or verified by this helper. Networking/filesystem examples may create persistent side effects. Do not run them as incidental test scaffolding. cpp_basics/structured_bindings.cpp uses unqualified string in its struct and needs a separate compiler fix/proof. No full-repository verification claim is valid.
