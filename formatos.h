#ifndef __FORMATOS_H__
#define __FORMATOS_H__

#include <string>

#ifdef __linux__
#define CLR_SCREEN "clear"
#include <unistd.h>
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#include <Windows.h>
#endif // __MINGW32__

const std::string fin_de_formato = "\033[0m";
const std::string subrayado = "\033[4m";
const std::string titilado = "\033[25m";
const std::string negrita = "\033[1m";
const std::string encabezado = "\033[3;37;40m";
const std::string fondo_color_blanco = "\033[3;30;47m";
const std::string fondo_color_rojo = "\033[48;5;88m";
const std::string fondo_color_anaranjado = "\033[48;5;130m";
const std::string fondo_color_amarillo = "\033[48;5;3m";
const std::string fondo_color_azul = "\033[48;5;4m";
const std::string fondo_color_purpura = "\033[48;5;5m";
const std::string fondo_color_aguaoscuro = "\033[38;5;23m";
const std::string fondo_color_gris = "\033[48;5;59m";
const std::string fondo_color_verde = "\033[48;5;2m";
const std::string TXT_RED_196 =  "\033[38;5;196m";
const std::string TXT_YELLOW_220 = "\033[38;5;220m";
const std::string fondo_color_gris_oscuro = "\033[48;5;235m";
const std::string fondo_color_marron = "\033[48;5;130m";

const std::string EMOJI_EDIFICIO = "\U0001f3e2";
#endif
