/**
 * The C++ file of information
 */

#include <qtdg-base-config.h>
#include <qtdg-base.h>

#include <iostream>

using std::cerr;
using std::endl;


void qtdgSharedLinkTest() {
  cerr << "If you see this text on stderr, that meant you can link the shared object library" << endl;
  cerr << "This library " << (qtdgIsGPU ? "": "do not ") << "use GPU with CUDA" << endl;
}

const int qtdgIsGPU () {
  return (IS_USING_GPU);
}
