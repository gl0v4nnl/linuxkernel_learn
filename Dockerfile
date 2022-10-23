FROM ubuntu:20.04

##
# Install needed packets via apt-get
#
ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update --fix-missing -y
RUN apt-get install -y git build-essential kernel-package fakeroot libncurses5-dev libssl-dev ccache bison flex libelf-dev dwarves
