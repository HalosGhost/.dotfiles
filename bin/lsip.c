#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main (int argc, char ** argv)
{   CURL * handle;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);
	handle = curl_easy_init();

	if ( handle )
    {   curl_easy_setopt(handle, CURLOPT_URL, "http://icanhazip.com");
		curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1);

		res = curl_easy_perform(handle);
		if ( ! res == CURLE_OK )
        {   curl_easy_cleanup(handle);
			curl_global_cleanup();
			fputs("Could not check IP address", stderr);
			exit(1);
		}
	}
	
	curl_easy_cleanup(handle);
	curl_global_cleanup();

	return 0;
}
