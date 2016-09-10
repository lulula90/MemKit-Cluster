/**
 *      copyright C hujian 2016 version 1.0.0
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MEMKIT_MEMKITUTILS_H
#define MEMKIT_MEMKITUTILS_H

#include <string>
#include <string.h>
#include <time.h>

#include "../core/MemKit.h"

typedef std::string String;

/**
 * an utils class.
 */
class MemKitUtils{
private:
    /**
     * just get the time mills
     * @return
     */
    long getMills(){
        return time((time_t*)NULL);
    }

protected:

public:
    /**
     * to string from int
     * @param number
     * @return
     */
    static String parseString(int number){
        if(number==0){
            return "0";
        }
        String result="";
        while(number){
            result=(char)(number%10+'0')+result;
            number/=10;
        }
        return result;
    }
    /**
     * from long
     * @param ln
     * @return
     */
    static String parseString(long ln){
        return parseString((int)ln);
    }
    /**
     * from db
     * @param db
     * @return
     */
    static String parseString(double db){
        if(db==0){
            return "0.0";
        }
        char buf[1024];
        sprintf(buf,"%f",db);
        return String(buf);
    }
    /**
     * like trim
     * @param source
     * @return
     */
    static String trim(String source){
        if(source.empty()){
            return source;
        }
        source.erase(0,source.find_first_not_of(" "));
        source.erase(source.find_last_not_of(" ")+1);
        return source;
    }
    /**
     * the split
     * @param source
     * @param del
     * @return
     */
    static std::vector<String> split(String source,String del)
    {
        source=trim(source);
        std::vector<String> vec;
        size_t  last=0;
        size_t  index=source.find_first_of(del,last);
        while(index!=std::string::npos){
            vec.push_back(source.substr(last,index-last));
            last=index+1;
            index=source.find_first_of(del,last);
        }
        if(index-last>0){
            vec.push_back(source.substr(last,index-last));
        }
        return vec;
    }
};

#endif //MEMKIT_MEMKITUTILS_H
