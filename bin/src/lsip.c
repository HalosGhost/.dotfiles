/*****************************\
* Get external IP address     *
* Author: Sam Stuewe (C) 2014 *
* License: GPLv3              *
\*****************************/

// Includes //
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Main Function //
int main ()
{   CURL * handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();

    if ( handle )
    {   curl_easy_setopt(handle, CURLOPT_URL, "http://icanhazip.com");
        curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1);

        res = curl_easy_perform(handle);
        if ( res != CURLE_OK )
        {   curl_easy_cleanup(handle);
            curl_global_cleanup();
            fputs("Could not check IP address\n", stderr);
            exit(1);
        }
    }
    
    curl_easy_cleanup(handle);
    curl_global_cleanup();

    return 0;
}
// vim: set tabstop=4 shiftwidth=4 expandtab:
