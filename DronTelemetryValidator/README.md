# Практичне завдання: Drone Telemetry Validator

## Мета

Створити невеликий C++ проєкт, який імітує отримання телеметрії дрона та перевіряє її коректність.

У процесі роботи потрібно закріпити:

* `try / catch / throw`;
* стандартні exceptions;
* власні exception-класи;
* inheritance;
* роботу з `.h` та `.cpp`;
* структуру C++ проєкту;
* CMake;
* компіляцію та запуск проєкту через CMake.

---

## 1. Структура проєкту

Створи наступну структуру:

```text
DroneTelemetry/
├── CMakeLists.txt
├── include/
│   ├── Telemetry.h
│   └── Validator.h
├── src/
│   ├── Telemetry.cpp
│   ├── Validator.cpp
│   └── main.cpp
└── README.md
```

---

## 2. Клас Telemetry

Створи структуру або клас `Telemetry` з такими полями:

```cpp
double latitude;
double longitude;
double altitude;
double battery;
```

Додай метод для виведення інформації про дрон.

Приклад:

```text
Latitude: 49.8397
Longitude: 24.0297
Altitude: 120 m
Battery: 78%
```

---

## 3. Validator

Створи клас `Validator`, який перевіряє отриману телеметрію.

Необхідно перевірити:

* `latitude` повинна бути від `-90` до `90`;
* `longitude` повинна бути від `-180` до `180`;
* `altitude` не може бути меншою за `0`;
* `battery` повинна бути від `0` до `100`.

Якщо значення неправильне — потрібно створити та викинути exception.

Наприклад:

```cpp
throw std::invalid_argument("Invalid latitude");
```

---

## 4. Власні Exception-класи

Створи власні exception-класи:

```text
TelemetryException
    ├── InvalidCoordinatesException
    ├── InvalidAltitudeException
    └── InvalidBatteryException
```

`TelemetryException` повинен наслідуватися від:

```cpp
std::runtime_error
```

Інші exception-класи повинні наслідуватися від `TelemetryException`.

Наприклад:

```cpp
class InvalidBatteryException : public TelemetryException {
public:
    InvalidBatteryException()
        : TelemetryException("Battery value is invalid") {}
};
```

Для кожного типу помилки повинно бути власне повідомлення.

---

## 5. Обробка помилок

У `main.cpp` використай `try/catch`.

Приклад:

```cpp
try {
    // validation
}
catch (const TelemetryException& e) {
    std::cerr << "Telemetry error: " << e.what() << '\n';
}
catch (const std::exception& e) {
    std::cerr << "Unknown error: " << e.what() << '\n';
}
```

Програма не повинна аварійно завершуватися при неправильних даних.

---

## 6. CMake

Створи `CMakeLists.txt`.

CMake повинен:

* мати мінімальну версію CMake;
* створювати проєкт;
* використовувати C++17 або новіше;
* створювати executable `drone_telemetry`;
* підключати `.cpp` файли;
* додавати папку `include/`.

Приклад:

```cmake
cmake_minimum_required(VERSION 3.20)

project(DroneTelemetry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    drone_telemetry
    src/main.cpp
    src/Telemetry.cpp
    src/Validator.cpp
)

target_include_directories(
    drone_telemetry
    PRIVATE
    include
)
```

---

## 7. Build через CMake

Компіляцію потрібно виконувати через CMake.

У корені проєкту:

```bash
mkdir build
cd build
```

Потім:

```bash
cmake ..
```

Після успішної конфігурації:

```bash
cmake --build .
```

Після цього запусти створений executable.

На Windows це може бути:

```bash
.\Debug\drone_telemetry.exe
```

або:

```bash
.\drone_telemetry.exe
```

залежно від генератора CMake.

---

# 8. Перевірка програми

Програма повинна коректно обробляти такі випадки.

### Тест 1 — правильні дані

```text
Latitude: 49.8397
Longitude: 24.0297
Altitude: 120
Battery: 78
```

Очікуваний результат:

```text
Telemetry is valid
```

---

### Тест 2 — неправильна latitude

```text
Latitude: 120
Longitude: 24.0297
Altitude: 120
Battery: 78
```

Програма повинна викинути та обробити відповідний exception.

---

### Тест 3 — неправильна longitude

```text
Latitude: 49.8397
Longitude: 250
Altitude: 120
Battery: 78
```

---

### Тест 4 — неправильна altitude

```text
Latitude: 49.8397
Longitude: 24.0297
Altitude: -10
Battery: 78
```

---

### Тест 5 — неправильний battery

```text
Latitude: 49.8397
Longitude: 24.0297
Altitude: 120
Battery: 150
```

---

# ⭐ Додаткове завдання

Додай можливість читати телеметрію з файлу:

```text
telemetry.txt
```

Формат файлу:

```text
49.8397 24.0297 120 78
```

Програма повинна:

1. відкрити файл;
2. перевірити, чи файл успішно відкрився;
3. прочитати значення;
4. створити об'єкт `Telemetry`;
5. передати його у `Validator`;
6. перевірити всі значення;
7. обробити можливі помилки через `try/catch`.

Якщо файл не відкрився, потрібно створити exception:

```cpp
throw std::runtime_error("Cannot open telemetry file");
```

---

# Додаткові вимоги

Не пиши весь код в одному файлі.

Логіку потрібно розділити:

* `Telemetry.h` — оголошення `Telemetry`;
* `Telemetry.cpp` — реалізація;
* `Validator.h` — оголошення `Validator` та exceptions;
* `Validator.cpp` — реалізація перевірок;
* `main.cpp` — запуск програми та обробка помилок;
* `CMakeLists.txt` — конфігурація збірки.

У корені проєкту не повинно бути `.o`, `.exe` та інших файлів збірки — для цього використовується окрема папка `build/`.

---

# Результат

У результаті повинен вийти повністю робочий C++ проєкт, який:

* збирається через CMake;
* запускається без помилок;
* перевіряє телеметрію;
* використовує `try/catch/throw`;
* має власні exception-класи;
* коректно обробляє неправильні дані;
* має розділення на `.h` та `.cpp`;
* має окрему папку `build/`.

## Що здати

1. Папку `DroneTelemetry`.
2. Вихідний код.
3. `CMakeLists.txt`.
4. `README.md` з інструкцією:

    * як налаштувати CMake;
    * як зібрати проєкт;
    * як запустити;
    * приклад роботи програми.
5. Не додавати папку `build/` до Git.