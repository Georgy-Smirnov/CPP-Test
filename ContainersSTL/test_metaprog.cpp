#include <iostream>
#include <vector>

//Fibonacci

template <int N>
struct Fib {
	static const int value = Fib<N-1>::value + Fib<N-2>::value;
};

template <>
struct Fib<0> {
	static const int value = 0;
};

template <>
struct Fib<1> {
	static const int value = 1;
};

//Is Prime

template <int N, int K>
struct IsPrimeHelper {
	static const bool value = N % K == 0 ? false : IsPrimeHelper<N, K-1>::value;
};

template <int N>
struct IsPrimeHelper<N, 1> {
	static const bool value = true;
};

template <int N>
struct IsPrime {
	static const bool value = IsPrimeHelper<N, N-1>::value;
};

//Dependent names

template <typename T>
struct S {
	static const int x = 1;
};

template <>
struct S<int> {
	typedef int x;
};

int a = 0;

template <typename T>
void f(T y) {
	S<T>::x * a;
}
// Если Т-int то создается указатель(объявление), иначе х умножается на а(выражение)!
// Компилятор считает, что имеет дело с переменной! х - зависимое имя.
// typename S<T>::x a; - для типа.

template <typename T>
struct SS {
	template <int N>
	struct A {};		
};

template <>
struct SS<int> {
	static const int A;
};

template <typename T>
void g() {
	SS<T>::A<10> a;
	// typename SS<T>::template A<10> a;
}

//Компилятор считает, что имеет дело с переменной и парсит <10> как меньше, 10, больше!

/*==================================================*/
/*================== Is Same =======================*/
/*==================================================*/
												/*==*/
template <typename T, typename U>				/*==*/
struct IsSame {									/*==*/
	static const bool value = false;			/*==*/
};												/*==*/
												/*==*/
template <typename T>							/*==*/
struct IsSame <T, T> {							/*==*/
	static const bool value = true;				/*==*/
};												/*==*/
												/*==*/
/*==================================================*/
/*==================================================*/
/*==================================================*/

/*==================================================*/
/*================= Enable If ======================*/
/*==================================================*/
												/*==*/
template <bool conditional, typename Type>		/*==*/
struct EnableIf;								/*==*/
												/*==*/
template <typename Type>						/*==*/
struct EnableIf<true, Type>	{					/*==*/												/*==*/
	typedef Type type;							/*==*/
};												/*==*/
												/*==*/
/*==================================================*/
/*==================================================*/
/*==================================================*/

/*==================================================*/
/*===============шаблонная print====================*/
/*==================================================*/

// template <typename T, typename = typename T::iterator> // C++11
// void print(T container)//, typename T::iterator* = nullptr)
// {
//     std::cout << "Values:{ ";
//     for(typename T::iterator it_begin = container.begin(); it_begin != container.end(); ++it_begin)
//         std::cout << *(it_begin) << " ";
//     std::cout << "}\n";
// }

// template <typename T>
// void print(int a) {
// 	std::cout << a << std::endl;
// }

template <typename T>
typename EnableIf<!std::is_integral<T>::value, void>::type print(T container) {
	std::cout << "Values:{ ";
    for(typename T::iterator it_begin = container.begin(); it_begin != container.end(); ++it_begin)
        std::cout << *(it_begin) << " ";
    std::cout << "}\n";
}

template <typename T>
typename EnableIf<std::is_integral<T>::value, void>::type print(T val) {
	std::cout << "Value:" << val << "\n";
}

//clang++ test_metaprog.cpp --std=c++11 && ./a.out
int main(void) {
	std::cout << Fib<10>::value << std::endl;
	std::cout << IsPrime<1001>::value << std::endl;
	std::cout << IsSame<int, int>::value << std::endl;

	std::vector<int> a;
	int q = 5;
	for (size_t i = 0; i < 10; ++i)
		a.push_back(i);
	print<std::vector<int> >(a);
	print<int>(q);
}

