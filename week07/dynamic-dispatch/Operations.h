
#include "OperationInterface.h"

class Add : public OperationInterface {
public:
    double compute(double a, double b) override {
        return a + b;
    }

    const char* name() override {
        return "Add";
    }
};

class Subtract : public OperationInterface {
public:
    double compute(double a, double b) override {
        return a - b;
    }

    const char* name() override {
        return "Subtract";
    }
};

class Multiply : public OperationInterface {
public:
    double compute(double a, double b) override {
        return a * b;
    }

    const char* name() override {
        return "Multiply";
    }
};

class Divide : public OperationInterface {
public:
    
    double compute(double a, double b) override {
        if (b == 0) throw runtime_error("Division by zero");
        return a / b;
    }

    const char* name() override {
        return "Divide";
    }
};