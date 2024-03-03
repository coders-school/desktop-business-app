FROM alpine:latest
ENV PROJECT_NAME=desktop-business-app

RUN apk update && apk add --no-cache g++ cmake make
RUN apk add --no-cache gtest-dev
RUN apk add qt6-qtbase-dev

WORKDIR /application
COPY . /application

RUN cmake -S . -B build && cmake --build build

ENTRYPOINT /app/bin/${PROJECT_NAME}
