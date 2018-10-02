#!/bin/bash


curl https://en.wikipedia.org/wiki/World_Happiness_Report\?action\=raw | grep -Eo "flag\|[A-Za-z]*\s*[A-Za-z]*" | awk -F'|' '{print $2}' | head -10
 
