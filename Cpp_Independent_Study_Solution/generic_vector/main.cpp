//#include <iostream>
//#include "generic_vector.h"
//#include "foo.h"
//
//int main5() {
//	{
//		gVector<Foo> v;
//
//		//v.reserve(10);
//		v.emplace_back(std::move(Foo()));
//		v.emplace_back(Foo());
//		v.pop_back();
//		v.emplace_back(Foo());
//		v.emplace_back(Foo());
//		v.emplace_back(Foo());
//		v.pop_back();
//
//		//gVector<Foo> v2 = v;
//		gVector<Foo> v2 = std::move(v);
//		v2.emplace_back(Foo());
//		v2.push_back(Foo());
//		//v2.emplace_back(Foo());
//
//		std::cout << "v  -------------------------------------\n";
//		for (size_t i = 0; i < v.size(); ++i) {
//			std::cout << v[i] << " ";
//		}
//		std::cout << "\n";
//
//		std::cout << "v2 -------------------------------------\n";
//		for (size_t i = 0; i < v2.size(); ++i) {
//			std::cout << v2[i] << " ";
//		}
//		std::cout << "\n";
//
//		std::cout << "v  -------------------------------------\n";
//		while (v.size() > 0) {
//			std::cout << v.pop_back() << " ";
//		}
//		std::cout << "\n";
//
//		std::cout << "v2 -------------------------------------\n";
//		while (v2.size() > 0) {
//			std::cout << v2.pop_back() << " ";
//		}
//		std::cout << "\n";
//	}
//
//	return 0;
//}
//
//int main3() {
//	{
//		gVector<std::string> v;
//
//		//v.reserve(10);
//		v.push_back("a");
//		v.push_back("b");
//		v.push_back("c");
//		v.push_back("d");
//		v.push_back("d");
//		v.push_back("a");
//		v.push_back("b");
//		v.push_back("c");
//		v.push_back("d");
//		v.push_back("d");
//		v.push_back("d");
//		v.push_back("a");
//		v.push_back("b");
//		v.push_back("c");
//		v.push_back("d");
//		v.push_back("d");
//		v[1] = "ja";
//
//		//gVector<std::string> v2;
//		gVector<std::string> v2 = v;
//		v2.push_back("p");
//		v2.push_back("h");
//		v2.push_back("i");
//		//v2 = v;
//		//v2 = std::move(v);
//
//		std::cout << "v  -------------------------------------\n";
//		for (size_t i = 0; i < v.size(); ++i) {
//			std::cout << v[i] << " ";
//		}
//		std::cout << "\n";
//
//		std::cout << "v2 -------------------------------------\n";
//		for (size_t i = 0; i < v2.size(); ++i) {
//			std::cout << v2[i] << " ";
//		}
//		std::cout << "\n";
//
//		std::cout << "v  -------------------------------------\n";
//		while(v.size() > 0) {
//			std::cout << v.pop_back() << " ";
//		}
//		std::cout << "\n";
//
//		std::cout << "v2 -------------------------------------\n";
//		while(v2.size() > 0) {
//			std::cout << v2.pop_back() << " ";
//		}
//		std::cout << "\n";
//	}
//
//	return 0;
//}
//
//int main2() {
//	{
//		gVector<int> v;
//
//		v.reserve(10);
//		v.push_back(2);
//		v.push_back(3);
//		v.push_back(4);
//		v.push_back(5);
//		v.push_back(5);
//		v.at(1) = 0;
//
//		gVector<int> v2;
//		//v2 = v;
//		v2 = std::move(v);
//
//		std::cout << "v  -------------------------------------\n";
//		for (size_t i = 0; i < v.size(); ++i) {
//			std::cout << v[i] << " ";
//		}
//		std::cout << "\n";
//
//		std::cout << "v2 -------------------------------------\n";
//		for (size_t i = 0; i < v2.size(); ++i) {
//			std::cout << v2[i] << " ";
//		}
//		std::cout << "\n";
//	}
//
//	return 0;
//}