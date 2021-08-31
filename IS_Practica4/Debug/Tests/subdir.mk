################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Tests/date_tests.cpp \
../Tests/login_tests.cpp \
../Tests/test_main.cpp 

OBJS += \
./Tests/date_tests.o \
./Tests/login_tests.o \
./Tests/test_main.o 

CPP_DEPS += \
./Tests/date_tests.d \
./Tests/login_tests.d \
./Tests/test_main.d 


# Each subdirectory must supply rules for building sources it contributes
Tests/%.o: ../Tests/%.cpp Tests/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


