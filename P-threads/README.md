
# WeatherApp

This project is a multithreaded weather application implemented using pthreads and C++. The application fetches weather data using the cpprestsdk and processes it concurrently to enhance performance.

## Features

- Multithreaded implementation using pthreads.
- Fetches weather data from an API.
- Utilizes cpprestsdk for HTTP requests and JSON parsing.
- Secure connections enabled with OpenSSL.

## Prerequisites

- cpprestsdk
- OpenSSL

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/weatherapp.git
   cd weatherapp
   ```

2. Build the project using CMake:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Usage

Run the application:

```bash
./WeatherApp
```

