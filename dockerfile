FROM gcc:13.2.0

WORKDIR /app

COPY tracker_http.cpp .
COPY httplib.h .

RUN g++ -std=c++11 tracker_http.cpp -o tracker_http

EXPOSE 80

CMD ["./tracker_http"]
