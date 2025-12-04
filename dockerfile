# FROM gcc:13.2.0

# WORKDIR /app

# COPY tracker.cpp .

# # build tracker
# RUN g++ -std=c++11 tracker.cpp -o tracker

# EXPOSE 6881

# CMD ["./tracker"]
# Image GCC chuẩn
FROM gcc:13.2.0

WORKDIR /app

# Copy code tracker
COPY tracker_http.cpp .

# Build tracker
RUN g++ -std=c++11 tracker_http.cpp -o tracker_http

# Render Free chỉ mở port 6881, expose ra host
EXPOSE 6881

# Chạy tracker
CMD ["./tracker_http"]

