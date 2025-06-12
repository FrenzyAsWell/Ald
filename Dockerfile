FROM alpine:latest
WORKDIR /Ald/

# define ARGs and ENVs

ARG CXX_compiler_name="g++"
ARG CC_compiler_name="gcc"
ARG MAKE_compiler_name="make"

ARG pkgs="cmake git ${CXX_compiler_name} ${CC_compiler_name} ${MAKE_compiler_name}"

ARG exec_name="client"
ARG current_build_dir="./build"
ARG current_modules_dir="./external"
ARG binary_dir="/usr/bin"

ARG CC="${binary_dir}/${CC_compiler_name}"
ARG CXX="${binary_dir}/${CXX_compiler_name}"

ENV CC="${CC}"
ENV CXX="${CXX}"

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

RUN cmake \ 
	-S ./ \
	-B "./${current_build_dir}/" \
	-D CMAKE_C_COMPILER="${CC}" \
	-D CMAKE_CXX_COMPILER="${CXX}" \
	-D CMAKE_MAKE_PROGRAM="${binary_dir}/${MAKE_compiler_name}"

RUN make -C "./${current_build_dir}/" -j $(nproc --all)

# CMD commands

CMD "./build/${exec_name}"

