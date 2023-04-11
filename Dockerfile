FROM ubuntu:latest


RUN apt-get update && apt-get install -y apt-utils build-essential cmake git libssl-dev libssl-dev




RUN git clone https://github.com/Azure/azure-iot-sdk-c.git --recursive && cd azure-iot-sdk-c && mkdir cmake && cd cmake && cmake .. && make

RUN git clone https://github.com/CohdaWireless/BSM.git && cd BSM/ && mkdir build && cd build/ && cmake .. && make

WORKDIR /app

COPY ./send_data.cpp .

RUN g++ -std=c++11 send_data.cpp -o send_data -laziotsharedutil -laziotprotocols -laziotiothubclient -lssl -lcrypto -lpthread -lBSM

CMD ["./send_data"]
