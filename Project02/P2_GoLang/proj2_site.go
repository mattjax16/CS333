package main

import (
	"fmt"
	"net/http"
	"strings"
)

func queryStrip(query string) map[string]string {

	//Initilize the empty query map
	var query_map map[string]string
	query_map = make(map[string]string)

	//split querys into theit key value pairs
	split_query := strings.Split(query,"&")

	//looping through to add the key value pairs
	// to the query map
	for i:=0; i < len(split_query);i++{

		//split the key-valu pairs
		key_val := strings.Split(split_query[i], "=")

		query_map[key_val[0]] = key_val[1]
	}

	return query_map
}


func webHelloWorld(w http.ResponseWriter, r *http.Request) {

	//Initilize the name map
	var name_map map[string]string = queryStrip(r.URL.RawQuery)


	fmt.Fprintf(w, "Hi there, %s %s !",name_map["fname"], name_map["lname"])
}

func main() {



	http.HandleFunc("/hello/", webHelloWorld)
	http.ListenAndServe(":8001", nil)
}
