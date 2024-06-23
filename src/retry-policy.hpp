#pragma once

template<typename operation_t, typename reset_t>
class retry_policy {
public:
    retry_policy(operation_t operation, reset_t reset) : 
    operation_{operation}, reset_{reset} {}
    auto operator()() {
        for (;;) {
            try {
                return operation_();
            } catch (std::exception const& e) {
                std::puts(e.what());
                reset_();
            }
        }
    }
private:
    operation_t operation_;
    reset_t reset_;
};
