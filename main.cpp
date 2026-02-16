#include <iostream>
#include <vector>
#include <thread>

// This function represents one "worker" painting a piece of the image
void render_segment(int start_row, int end_row) {
    for (int y = start_row; y < end_row; ++y) {
        for (int x = 0; x < 800; ++x) {
            // Ray tracing math goes here
        }
    }
}

int main() {
    unsigned int cores = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    int rows_per_thread = 600 / cores;

    // Launching multiple threads (Multi-threading claim)
    for (unsigned int i = 0; i < cores; ++i) {
        threads.push_back(std::thread(render_segment, i * rows_per_thread, (i + 1) * rows_per_thread));
    }

    for (auto& t : threads) t.join();
    std::cout << "Render Complete using " << cores << " threads." << std::endl;
    return 0;
}
