FROM ubuntu:noble AS build
ENV PROJECT_NAME=desktop-business-app
WORKDIR /application

COPY /dependencies.sh /application/

RUN /application/dependencies.sh