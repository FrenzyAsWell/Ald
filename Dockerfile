FROM alpine:latest
WORKDIR /Ald/

# define ARGs

ARG pkgs="cmake git build-base"
ARG current_build_dir="./build"
ARG current_modules_dir="./external"

# COPY files

COPY ./src/ ./src/ 
COPY ./CMakeLists.txt ./CMakeLists.txt
RUN mkdir -p ./${current_modules_dir}/
RUN mkdir -p ./${current_build_dir}/

# RUN commands

RUN echo "@main https://dl-cdn.alpinelinux.org/alpine/edge/main" | tee -a /etc/apk/repositories
RUN echo "@community https://dl-cdn.alpinelinux.org/alpine/edge/community" | tee -a /etc/apk/repositories
RUN echo "@testing https://dl-cdn.alpinelinux.org/alpine/edge/testing" | tee -a /etc/apk/repositories

RUN apk upgrade --no-cache -a && \
	apk add --no-cache ${pkgs}

RUN cmake -S ./ -B "./${current_build_dir}/"
RUN make -C "./${current_build_dir}/" -j $(nproc --all)

# CMD commands

CMD "./build/Ald_TaskManager"

