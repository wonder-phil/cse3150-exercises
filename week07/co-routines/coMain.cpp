#include <coroutine>
#include <iostream>

using namespace std;

template<typename T>
struct generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        T value;

        auto get_return_object() {
            return generator{handle_type::from_promise(*this)};
        }

        auto initial_suspend() { return std::suspend_always{}; }
        auto final_suspend() noexcept { return std::suspend_always{}; }

        auto yield_value(T v) {
            value = v;
            return std::suspend_always{};
        }

        void return_void() {}
        void unhandled_exception() { std::exit(1); }
    };

    handle_type coro;

    generator(handle_type h) : coro(h) {}
    ~generator() { if (coro) coro.destroy(); }

    bool next() {
        coro.resume();
        return !coro.done();
    }

    T value() {
        return coro.promise().value;
    }
};


generator<int> generatorForNumbers(int beginInt, int inc = 1) {
    while (true)
        co_yield beginInt += inc;
}


int main() {
    cout << "-------" << endl;
    auto numbers = generatorForNumbers(-10);

     for (int i = 0; i < 10; i++) {
        numbers.next();
        std::cout << numbers.value() << "\n";
    }

    cout << "-------" << endl;

    return 0;
}