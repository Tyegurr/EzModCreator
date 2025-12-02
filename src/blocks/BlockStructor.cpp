#include "BlockStructor.hpp"

int BlockStructor::getNumberOfInputs() {
    if (inputs == nullptr) return 0;
    return inputs->getAllInputs().size();
}
int BlockStructor::getNumberOfOutputs() {
    if (outputs == nullptr) return 0;
    return outputs->getAllOutputs().size();
}