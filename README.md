u8 lib
----

The library is easy to use interface for Boost.Locale. The main idea is convert all application strings using utf-8 charset and store it in std::string. After that if you want to work with char array you would use methods from std::string library otherwise you can use the u8 methods to work with it as letter sequence.
