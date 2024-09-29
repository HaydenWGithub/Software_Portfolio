#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <random>


using namespace std;
using namespace std::chrono;

template<typename Func>
void measure_function_time(Func func, const string& function_name, auto param) {
    //measure the time before the function call
    auto start = steady_clock::now();
    func(param, 's');
    //measure the time when the function ends
    auto end = steady_clock::now();
    //duration fo the function should be the difference between each time that we use.
    duration<double> diff = end - start;
    //print time to console
    cout << "Time taken by " << function_name << ": " << diff.count() << " s" << endl;
}

// - count char using slow repeated string::find_first_of
int count_char_using_find_first_of(string s, char delim)
{
    int count = 0;
    // note: string::size_type pos = s.find_first_of(delim);
    auto pos = s.find_first_of(delim);
    while ( (pos = s.find_first_of(delim, pos)) != string::npos)
    {
        count++;
        pos++;
    }
    return count;
}

// - count char using fast std::count
int count_char_using_count(string s, char delim)
{
    return count(s.begin(), s.end(), delim);
}


void exponential_rampup_test()
{
    cout << " << Exponential Ramp-up Test >> " << endl;
    int total;
    // ull (suffix) == "unsigned long long" in c
    for (auto size = 1ull; size < 1000000000ull; size *= 100)
    {
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(size, 42);
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / size << "s/int" << endl;

        // TIP: time in nanoseconds? Cast result of chrono::duration.count() ...
        // auto _dur = duration_cast<nanoseconds>( end - start ).count();
        // cout << _dur << endl;
    }
    cout << "done." << endl;
}

void linear_rampup_test()
{
    cout << " << Linear Ramp-up Test >> " << endl;
    int total;
    for (auto size = 1; size <= 5; size += 1)
    {
        int vec_size = size * 10000;
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(vec_size, 42);
        // std::accumulate (from <numeric>) collects from begin, to end
        // - in this case (default) it is the sum total of all the values in v
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << vec_size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / vec_size << "s/int" << endl;
    }
    cout << "done." << endl;
}

string generate_random_string(int length) {
    static const char alphabet[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist(0, sizeof(alphabet) - 2);
    string result;
    result.reserve(length);
    for (int i = 0; i < length; ++i) {
        result += alphabet[dist(rng)];
    }
    return result;
}



int main()
{
    // Simple wrapper around a linaer set of time tests
    linear_rampup_test();
    
    // Measure the execution time of linear_rampup_test
    //measure_function_time(linear_rampup_test, "linear_rampup_test");
    
    // Simple wrapper around an exponential set of time tests
    exponential_rampup_test();
    
    // Measure the execution time of exponential_rampup_test
    //measure_function_time(exponential_rampup_test, "exponential_rampup_test");
    
    // Compare the two different methods of counting in a string
    // - show result in nanoseconds?
    string s1 = "This is a really simple string but it will do for testing.";
    int result;
    result = count_char_using_find_first_of(s1, 's');
    cout << "result: " << result << endl;
    measure_function_time(count_char_using_find_first_of, "count_char_using_find_first_of", s1);
    result = count_char_using_count(s1, 's');
    cout << "result: " << result << endl;
    measure_function_time(count_char_using_count, "count_char_using_count", s1);
    
    cout << "String Size, Find First Of Time (s), Count Time (s)" << endl;

        for (int size = 1000; size <= 10000; size += 1000) {
            string s1 = generate_random_string(size);
            
            cout << "\n count_char_using_find_first_of at size " << size << ":" << endl;
            measure_function_time(count_char_using_find_first_of,"count_char_using_find_first_of", s1);
            cout << "count_char_using_count at size " << size << ":" << endl;
            measure_function_time(count_char_using_count, "count_char_using_count", s1);
            
            
        }

}

