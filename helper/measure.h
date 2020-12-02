#include <tuple>
#include <chrono>

class measure
{
      public:
	template <typename T, class... Ts>
	// Measures the time it takes to run a function
	static auto function(T&& func, Ts&&... params)
		-> std::tuple<decltype(func(std::forward<Ts>(params)...)),
			      std::chrono::microseconds>
	{
		// get time before function invocation
		const auto start = std::chrono::high_resolution_clock::now();
		// function invocation using perfect forwarding
		const auto returnvalue =
			std::forward<T>(func)(std::forward<Ts>(params)...);
		// get time after function invocation
		const auto stop = std::chrono::high_resolution_clock::now();
		return std::make_tuple(
			returnvalue,
			std::chrono::duration_cast<std::chrono::microseconds>(
				stop - start));
	}
};