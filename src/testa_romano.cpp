// Copyright[2021] <Hyago Gabriel>
#define CATCH_CONFIG_MAIN
#include "../include/romano.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Testa se formato da entrada é valida", "[romanToArabic]") {
    REQUIRE(romanToArabic(" ") == -1);
    REQUIRE(romanToArabic("~") == -1);
    REQUIRE(romanToArabic("0") == -1);
    REQUIRE(romanToArabic("A") == -1);
    REQUIRE(romanToArabic("MU") == -1);
    REQUIRE(romanToArabic("i") == -1);
    REQUIRE(romanToArabic("IIIIIIIIIIIIIIIIIIIIIIIIIIIIII") == -1);
}

TEST_CASE("Testa retorno da func para digitos base", "romanToArabic") {
    REQUIRE(romanToArabic("I") == 1);
    REQUIRE(romanToArabic("V") == 5);
    REQUIRE(romanToArabic("X") == 10);
    REQUIRE(romanToArabic("L") == 50);
    REQUIRE(romanToArabic("C") == 100);
    REQUIRE(romanToArabic("D") == 500);
    REQUIRE(romanToArabic("M") == 1000);
}

TEST_CASE("Testa escopo do programa", "romanToArabic") {
    REQUIRE(romanToArabic("MMMI") == -1);
    REQUIRE(romanToArabic("MMMV") == -1);
    REQUIRE(romanToArabic("MMMX") == -1);
    REQUIRE(romanToArabic("MMML") == -1);
    REQUIRE(romanToArabic("MMMC") == -1);
    REQUIRE(romanToArabic("MMMD") == -1);
}

TEST_CASE("Testa retorno da func para digitos com subtração", "romanToArabic") {
    REQUIRE(romanToArabic("IV") == 4);
    REQUIRE(romanToArabic("CD") == 400);
    REQUIRE(romanToArabic("CM") == 900);
    REQUIRE(romanToArabic("VL") != 45);
    REQUIRE(romanToArabic("VC") != 95);
    REQUIRE(romanToArabic("VD") != 495);
    REQUIRE(romanToArabic("VM") != 995);
    REQUIRE(romanToArabic("IL") == -1);
    REQUIRE(romanToArabic("IC") == -1);
    REQUIRE(romanToArabic("ID") == -1);
    REQUIRE(romanToArabic("IM") == -1);
    REQUIRE(romanToArabic("XM") == -1);
    REQUIRE(romanToArabic("DM") == -1);
    REQUIRE(romanToArabic("LC") == -1);
    REQUIRE(romanToArabic("IIV") == -1);
    REQUIRE(romanToArabic("VXL") == -1);
    REQUIRE(romanToArabic("IIX") == -1);
    REQUIRE(romanToArabic("XXL") == -1);
    REQUIRE(romanToArabic("XXD") == -1);
    REQUIRE(romanToArabic("IVI") == -1);
    REQUIRE(romanToArabic("XIL") == -1);
    REQUIRE(romanToArabic("MIM") == -1);
    REQUIRE(romanToArabic("IXI") == -1);
}

TEST_CASE("Testa exceção para digitos repetidos", "romanToArabic") {
    REQUIRE(romanToArabic("IIII") == -1);
    REQUIRE(romanToArabic("VV") == -1);
    REQUIRE(romanToArabic("XXXX") == -1);
    REQUIRE(romanToArabic("LL") == -1);
    REQUIRE(romanToArabic("CCCC") == -1);
    REQUIRE(romanToArabic("DD") == -1);
    REQUIRE(romanToArabic("MMMM") == -1);
}
