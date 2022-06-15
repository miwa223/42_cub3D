#!/bin/bash

RESET="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
WHITE="\033[37m"

NB=0

compare_result()
{
    TEST_COMMAND=$1
    EXPECT=$2
    ACTUAL=$3

    if [ "$EXPECT" = "$ACTUAL" ]; then
        printf " $GREEN$1 ✓ \n$RESET"
    else
        # diff <(echo ${EXPECT}) <(echo ${ACTUAL})
        printf " $RED$1 x \n$RESET"
        printf "\n"
        printf $RED" Your output : \n%.20s\n $RED$ACTUAL\n%.020s$RESET\n"
        printf $YELLOW" Expected output : \n%.20s\n $YELLOW$EXPECT\n%.020s$RESET\n"
    fi
}

e_output_test ()
{
    EXPECTED_OUT="Error\n"
    FLAG=$2

    if [ "$FLAG" = "arg" ]; then
        EXPECTED_OUT="${EXPECTED_OUT}Invalid arguments\n"
    elif [ "$FLAG" = "xpm" ]; then
        EXPECTED_OUT="${EXPECTED_OUT}Xpm to image conversion failed\n"
    elif [ "$FLAG" = "open" ]; then
        EXPECTED_OUT="${EXPECTED_OUT}Open failed\n"
    elif [ "$FLAG" = "read" ]; then
        EXPECTED_OUT="${EXPECTED_OUT}Read failed\n"
    elif [ "$FLAG" = "cubfile" ]; then
        EXPECTED_OUT="${EXPECTED_OUT}Invalid cubfile\n"
    elif [ "$FLAG" = "map" ]; then
        EXPECTED_OUT="${EXPECTED_OUT}Invalid map\n"
    fi

    EXPECTED_OUT=$(echo -e $EXPECTED_OUT >"test/results/expect")
    mv "./test/results/expect" "test/results/expect_$FLAG$NB"
    EXPECTED_OUT=`cat test/results/expect_$FLAG$NB`

    ACTUAL_OUT=$(echo $1 | bash 2>"./test/results/actual")
    mv "./test/results/actual" "./test/results/actual_$FLAG$NB"
    ACTUAL_OUT=`cat test/results/actual_$FLAG$NB`

    compare_result "$1" "$EXPECTED_OUT" "$ACTUAL_OUT"
    NB=$(( $NB+1 ))
}
