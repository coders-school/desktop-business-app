#pragma once

#include <any>
#include <list>
#include <map>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <stdexcept>
#include <memory>

class ObjectPlus
{
    ObjectPlus() {}
    ~ObjectPlus() {}
    static std::map<std::string, std::list<std::any>> all_extents_;

  public:
    template <typename T>
    static void addObject(const T& object) {
        std::string key = typeid(T).name();

        if(auto it = all_extents_.find(key); it != all_extents_.end()){
            it->second.push_back(std::any(object));
        }else{
            all_extents_[key].push_back(std::any(object));
        }
    }

    template <typename T> 
    static std::list<std::any> getExtent(){
        std::string key = typeid(T).name();

        if(auto it = all_extents_.find(key); it != all_extents_.end()){
            return it->second;
        }else{
            throw std::invalid_argument("Class " + key + "not found in all extents");
        }
    }

    template <typename T>
    static void removeFromExtent(T& object){
        std::string key = typeid(T).name();

        if(auto it = all_extents_.find(key); it != all_extents_.end()){
          it->second.erase(std::find_if(it->second.begin(), it->second.end(), [&object](const auto& elem){
            T* p = const_cast<T*>(std::any_cast<T>(&elem));
            return p == std::addressof(object);
          }));
        }
    }
};
