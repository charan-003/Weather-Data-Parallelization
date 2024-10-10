#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <cpprest/http_client.h>

using namespace std;
using namespace std::chrono_literals;
using namespace web;
using namespace web::http;
using namespace web::http::client;

void RefreshForecast(const string& city) {
    while (true) {
        // HTTP client to make the request
        http_client client(U("https://api.openweathermap.org/data/2.5"));
        uri_builder builder(U("/weather"));
        builder.append_query(U("q"), utility::conversions::to_string_t(city));
        builder.append_query(U("appid"), utility::conversions::to_string_t("78abcb27ef00f1f0c0f862776675419c"));
        builder.append_query(U("units"), U("metric"));

        http_request request(methods::GET);
        request.set_request_uri(builder.to_string());

        try {
            client.request(request).then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    throw runtime_error("Failed to get a valid response from server");
                }
            }).then([&city](json::value body) {
                try {
                    double temperature = body[U("main")][U("temp")].as_double();
                    int humidity = body[U("main")][U("humidity")].as_integer();
                    string weather = utility::conversions::to_utf8string(body[U("weather")][0][U("main")].as_string());

                    cout << "\nWeather update for " << city << ":\n";
                    cout << "\tTemperature: " << temperature << " C" << endl;
                    cout << "\tHumidity: " << humidity << " %" << endl;
                    cout << "\tWeather: " << weather << endl;
                } catch (const exception& e) {
                    cerr << "Error processing JSON: " << e.what() << endl;
                }
            }).wait();
        } catch (const exception& e) {
            cerr << "Request failed: " << e.what() << endl;
        }

        // Wait for 2 seconds before fetching the data again
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main() {
    cout << "My Weather App\n" << endl;

    // Ask the user for the city name
    cout << "Enter city name: ";
    string city;
    getline(cin, city); // Allow user to enter a city with spaces

    // Start a thread to refresh the weather for the user-specified city
    thread bgWorker(RefreshForecast, city);

    system("pause>nul");
    bgWorker.join(); // Ensure the thread is joined before exiting
    return 0;
}
