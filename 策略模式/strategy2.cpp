class Context;
class TaxStrategy {
public:
    virtual double Calculate(const Context& context) = 0;
    virtual ~TaxStrategy() { }
};

class CNTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) {
        // ...
    }
};

class USTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) {
        // ...
    }
};

class DETax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) {
        // ...
    }
};

// À©Õ¹
class FRTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) {
        // ...
    }
};

class SalesOrder {
private:
    TaxStrategy *strategy;

public:
    SalesOrder(SalesOrderFactory *straregyFactory) {
        this->strategy = straregyFactory->NewStrategy();
    }

    ~SalesOrder() {
        delete strategy;
    }

    double CalculateTax() {
        // ...
        Context context();

        double val = strategy->Calculate(context);
        // ...
    }
};