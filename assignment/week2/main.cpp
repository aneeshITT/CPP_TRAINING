#include <iostream>
#include <dlfcn.h>

#include "MatrixApplication.h"

int main() {

    void* handle = dlopen("./lib/libmatrixOperation.so", RTLD_LAZY);

    if (!handle) {
        std::cout << "Error loading library\n";
        return 1;
    }

    AddFunc addMatrices = (AddFunc)dlsym(handle, "addMatrices");
    MulFunc multiplyMatrices = (MulFunc)dlsym(handle, "multiplyMatrices");

    if (!addMatrices || !multiplyMatrices) {
        std::cout << "Error loading functions\n";
        return 1;
    }

    runMatrixApplication(addMatrices, multiplyMatrices);

    dlclose(handle);

    return 0;
}
