# Parallel Ray Tracer (High-Performance Computing)
A high-performance C++11 ray tracer developed to explore low-level system optimization, concurrency, and hardware-accelerated math. This project demonstrates a deep dive into system architecture by squeezing maximum performance out of quad-core hardware.

Performance Highlights:
4.8x Speedup: Achieved significant performance gains on quad-core hardware through tiered optimization.
Latency Reduction: Minimized heap fragmentation and cache misses via custom memory management.

Key Technical Features:
1. Multi-Threaded Processing
Leveraged C++11 concurrency primitives (std::thread) to parallelize the rendering pipeline.
Implemented a tile-based rendering strategy to distribute pixel calculations across all available CPU cores, maximizing hardware utilization.

2. SIMD Optimizations
Utilized Single Instruction, Multiple Data (SIMD) intrinsics to vectorize ray-sphere intersection logic.
Processed multiple floating-point operations in a single clock cycle, providing the "extra" efficiency boost beyond standard multi-threading.

3. Custom Memory Allocators
Designed and implemented Arena Allocators to manage object lifecycles during the render pass.
Reduced heap fragmentation by pre-allocating contiguous memory blocks, drastically improving CPU cache hit rates and overall execution speed.

# Building and Running:
This project uses CMake to handle cross-platform builds and optimization flags. To build the tracer with full hardware acceleration:

1. Prerequisites
Compiler: GCC 7+, Clang 5+, or MSVC 2017+ (supporting C++11) 
Build System: CMake 3.10+

2. Build Instructions
Create a dedicated build directory to keep the source clean:
```bash
mkdir build && cd build
```

Generate build files and configure with release optimizations:
```
cmake -DCMAKE_BUILD_TYPE=Release ..
```
Compile the executable:
```
make -j$(nproc)
```
3. Execution
After a successful build, run the binary to generate the render:
./RayTracer

The output will be saved as a high-resolution image in the docs/ or root directory.
