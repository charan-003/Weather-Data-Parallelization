
# Weather Forecast Application

This is a simple weather forecasting command-line application built in C++ that fetches weather data from the OpenWeatherMap API. It utilizes parallelism through OpenMP to run tasks concurrently. The application is implemented using the `cpprestsdk` library for handling HTTP requests.

## Features

- Fetches real-time weather data (temperature, humidity, and weather conditions) from the OpenWeatherMap API.
- Supports concurrent execution using OpenMP.
- Handles JSON responses from the API using the C++ REST SDK.

## Requirements

To compile and run the project, ensure the following dependencies are installed:

- **g++** (with OpenMP support)
- **libomp** (OpenMP library)
- **cpprestsdk** (C++ REST SDK)
- **Boost** (for Boost system libraries)
- **OpenSSL** (for SSL/crypto libraries)

### Install Dependencies

On macOS, you can install the required dependencies using Homebrew:

```bash
brew install libomp
brew install cpprestsdk
brew install boost
brew install openssl
```

## Compilation

To compile the project, you can use the following command:

```bash
g++ -Xpreprocessor -fopenmp \
-I/opt/homebrew/Cellar/libomp/19.1.2/include \
-L/opt/homebrew/Cellar/libomp/19.1.2/lib \
-I/opt/homebrew/Cellar/cpprestsdk/2.10.19/include \
-L/opt/homebrew/Cellar/cpprestsdk/2.10.19/lib \
-I/opt/homebrew/include \
-L/opt/homebrew/lib \
-lomp -lcpprest -lboost_system -lssl -lcrypto \
-std=c++14 -o weather_openmp weather_openmp.cpp
```

### Explanation of the Compilation Command:

- **`-Xpreprocessor -fopenmp`**: Enables OpenMP support.
- **`-I` and `-L`**: Includes and links the necessary libraries for OpenMP, cpprestsdk, Boost, SSL, and Crypto.
- **`-lomp`**: Links the OpenMP library.
- **`-lcpprest`**: Links the C++ REST SDK library.
- **`-lboost_system`**: Links the Boost system library.
- **`-lssl -lcrypto`**: Links the OpenSSL and Crypto libraries.
- **`-std=c++14`**: Specifies the C++14 standard.

## Running the Application

Once the application is compiled, run it using the following command:

```bash
./weather_openmp
```

You will be prompted to enter the name of the city for which you want the weather forecast. For example:

```
My Weather App

Enter city name: London

Weather update for London:
    Temperature: 15.5 C
    Humidity: 65 %
    Weather: Clear
```

