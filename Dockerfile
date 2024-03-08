FROM ubuntu:mantic as BUILD
ENV PROJECT_NAME=desktop-business-app

RUN apt update -y && \
    apt install -y libgtest-dev cmake make g++ && \
    apt install -y qt6-base-dev 
RUN apt install -y libgl1-mesa-dev

WORKDIR /application
COPY . /application

RUN cmake -S . -B build && cmake --build build

RUN /application/bin/${PROJECT_NAME}-ut

FROM ubuntu:mantic as FINAL
ENV PROJECT_NAME=desktop-business-app

RUN apt update -y && \
    apt install -y libgtest-dev cmake make g++ && \
    apt install -y qt6-base-dev 
RUN apt install -y libgl1-mesa-dev

WORKDIR /application
COPY . /application

ENTRYPOINT /application/bin/${PROJECT_NAME} 
