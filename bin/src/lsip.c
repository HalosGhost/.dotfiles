/*****************************\
* Get external IP address     *
* Author: Sam Stuewe (C) 2014 *
* License: GPLv3              *
\*****************************/

// Includes //
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <curl/curl.h>

// Forward Declarations //
void _usage (int status);

// Main Function //
int main (int argc, char ** argv) {
    char flag_service = '4';

    if ( argc <= 1 ) {
        _usage(1);
    } else {
        static struct option os [] = {
            /* Flags */
            { "help",   no_argument,   0, 'h' },
            { "ipv4",   no_argument,   0, '4' },
            { "ipv6",   no_argument,   0, '6' },
        };

        int i = 0;

        for ( int c = 0; c != -1; c = getopt_long(argc, argv, "h46", os, &i) ) {
            switch ( c ) {
                case 'h':
                    _usage(0);
                    break;

                case '4':
                    flag_service = '4';
                    break;

                case '6':
                    flag_service = '6';
                    break;
            }
        }
    }

    curl_global_init(CURL_GLOBAL_ALL);
    CURL * handle = curl_easy_init();

    if ( handle ) {
        curl_easy_setopt(handle, CURLOPT_URL, "https://icanhazip.com");
        curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(handle, CURLOPT_IPRESOLVE,
                         (flag_service == '4' ? 
                          CURL_IPRESOLVE_V4 : 
                          CURL_IPRESOLVE_V6));

        if ( (CURLcode )curl_easy_perform(handle) != CURLE_OK ) {
            curl_easy_cleanup(handle);
            curl_global_cleanup();
            fputs("Could not check IP address\n", stderr);
            exit(1);
        }
    }
    
    curl_easy_cleanup(handle);
    curl_global_cleanup();

    return 0;
}

void _usage (int status) {
    fputs("Usage: lsip [options]\n\n"
          "Options:\n"
          "  -h, --help\tprint this message and exit\n"
          "  -4, --ipv4\tcheck external ipv4 address\n"
          "  -6, --ipv6\tcheck external ipv6 address\n",
          (status == 0 ? stdout : stderr));
    exit(status);
}
// vim: set tabstop=4 shiftwidth=4 expandtab:
