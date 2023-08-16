#include <vector>
#include <stdio.h>
#include <iostream>
#include "pack109.hpp"

vec pack109::serialize(bool item) {
  vec bytes;
  if (item == true) {
    bytes.push_back(PACK109_TRUE);
  } else {
    bytes.push_back(PACK109_FALSE);
  }
  return bytes;
}

bool pack109::deserialize_bool(vec bytes) {
  if (bytes.size() < 1) {
     throw;
  }

  if (bytes[0] == PACK109_TRUE) {
    return true;
  } else if (bytes[0] == PACK109_FALSE) {
    return false;
  } else {
    throw;
  }

}

vec pack109::serialize(u8 item) {
  vec bytes;
  bytes.push_back(PACK109_U8);
  bytes.push_back(item);
  return bytes;
}

u8 pack109::deserialize_u8(vec bytes) {
  if (bytes.size() < 2) {
    throw;
  }
  if (bytes[0] == PACK109_U8) {
    return bytes[1];
  } else {
    throw;
  }
}

void pack109::printVec(vec &bytes) {
  printf("[ ");
  for (int i = 0; i < bytes.size(); i++) {
    printf("%x ", bytes[i]);
  }
  printf("]\n");
}

vec pack109::serialize(u32 item) {
  vec bytes;
  int mask = 0x000000FF;
  int i = (sizeof(item) * 2) - 2;
  bytes.push_back(PACK109_U32);
  for (i; i >= 0; i -= 2) {
    u8 byte = ((item >> i * 4) & mask);
    bytes.push_back(byte);
  }
  return bytes;
}
  
u32 pack109::deserialize_u32(vec bytes) {
  if (bytes.size() < 5) {
    throw;
  }
  u32 item = 0;
  if (bytes[0] == PACK109_U32) {
    int j = (sizeof(u32) * 2) - 2;
    for (int i = 1; i < sizeof(u32)+2; i++) {
      u32 shift = (u32) bytes[i] << j * 4;
      item = item | shift;
      j -= 2;
    }
    return item;
  } 
  else {
    throw;
  }
}

vec pack109::serialize(u64 item) {
  vec bytes;
  int mask = 0x00000000000000FF;
  int i = (sizeof(item) * 2) - 2;
  bytes.push_back(PACK109_U64);
  for (i; i >= 0; i -= 2) {
    u8 byte = ((item >> i * 4) & mask);
    bytes.push_back(byte);
  }
  return bytes;
}

vec pack109::serialize2(u64 item) {
  vec bytes;
  int mask = 0x00000000000000FF;
  int i = (sizeof(item) * 2) - 2;
  //bytes.push_back(PACK109_U64);
  for (i; i >= 0; i -= 2) {
    u8 byte = ((item >> i * 4) & mask);
    bytes.push_back(byte);
  }
  return bytes;
}
  
u64 pack109::deserialize_u64(vec bytes) {
  if (bytes.size() < 9) {
    throw;
  }
  u64 item = 0;
  if (bytes[0] == PACK109_U64) {
    int j = (sizeof(u64) * 2) - 2;
    for (int i = 1; i < sizeof(u64)+2; i++) {
      u64 shift = (u64) bytes[i] << j * 4;
      item = item | shift;
      j -= 2;
    }
    return item;
  } 
  else {
    throw;
  }
}

vec pack109::serialize(i8 item) {
  vec bytes;
  bytes.push_back(PACK109_I8);
  bytes.push_back(item);
  return bytes;
}
  
i8 pack109::deserialize_i8(vec bytes) {
  if (bytes.size() < 2) {
    throw;
  }
  if (bytes[0] == PACK109_I8) {
    return bytes[1];
  } else {
    throw;
  }
}

vec pack109::serialize(i32 item) {
  vec bytes;
  int mask = 0x000000FF;
  int i = (sizeof(item) * 2) - 2;
  bytes.push_back(PACK109_I32);
  for (i; i >= 0; i -= 2) {
    i8 byte = ((item >> i * 4) & mask);
    bytes.push_back(byte);
  }
  return bytes;
}
  
  
i32 pack109::deserialize_i32(vec bytes) {
  if (bytes.size() < 5) {
    throw;
  }
  i32 item = 0;
  if (bytes[0] == PACK109_I32) {
    int j = (sizeof(i32) * 2) - 2;
    for (int i = 1; i < sizeof(i32)+2; i++) {
      i32 shift = (i32) bytes[i] << j * 4;
      item = item | shift;
      j -= 2;
    }
    return item;
  } 
  else {
    throw;
  }
}

vec pack109::serialize(i64 item) {
  vec bytes;
  int mask = 0x00000000000000FF;
  int i = (sizeof(item) * 2) - 2;
  bytes.push_back(PACK109_I64);
  for (i; i >= 0; i -= 2) {
    i8 byte = ((item >> i * 4) & mask);
    bytes.push_back(byte);
  }
  return bytes;
}
  
  
i64 pack109::deserialize_i64(vec bytes) {
  if (bytes.size() < 9) {
    throw;
  }
  i64 item = 0;
  if (bytes[0] == PACK109_I64) {
    int j = (sizeof(i64) * 2) - 2;
    for (int i = 1; i < sizeof(i64)+2; i++) {
      i64 shift = (i64) bytes[i] << j * 4;
      item = item | shift;
      j -= 2;
    }
    return item;
  } 
  else {
    throw;
  }
}

vec pack109::serialize(f32 item) {
  vec bytes;
  const unsigned char * f = reinterpret_cast<const unsigned char*>(&item);
  bytes.push_back(PACK109_F32);
  for (size_t i = sizeof(item); i > 0; i--) {
    bytes.push_back(f[i - 1]);
  }
  return bytes;
}
  
  
f32 pack109::deserialize_f32(vec bytes) {
  if (bytes.size() < 5) {
    throw;
  }
  u32 item = 0;
  if (bytes[0] == PACK109_F32) {
    int j = (sizeof(f32) * 2) - 2;
    for (int i = 1; i < sizeof(f32)+2; i++) {
    u32 shift = (u32) bytes[i] << j * 4;
      item = item | shift;
      j -= 2;
    }
    return item;
  } 
  else {
    throw;
  }
}

vec pack109::serialize(f64 item) {
  vec bytes;
  unsigned char * f = reinterpret_cast<unsigned char*>(&item);
  bytes.push_back(PACK109_F64);
  for (size_t i = sizeof(item); i > 0; i--) {
    bytes.push_back(f[i - 1]);
  }
  return bytes;
}
  
f64 pack109::deserialize_f64(vec bytes) {
  if (bytes.size() < 9) {
    throw;
  }
  long item = 0;
  if (bytes[0] == PACK109_F64) {
    int j = (sizeof(f64) * 2) - 2;
    for (int i = 0; i < sizeof(f64); i++) {
      long shift = (long) bytes[i] << j * 8;
      item = item | shift;
      j -= 2;
    }
    return item;
  } 
  else {
    throw;
  }
}

vec pack109::serialize(string item) {
  vec bytes;
  if (item.size() > 4) {
    bytes.push_back(PACK109_S16);
  } else {
    bytes.push_back(PACK109_S8);
  }
  for (int i = 0; i < item.size(); i++) {
      bytes.push_back(item.at(i));
  }
  return bytes;
}

vec pack109::serialize2(string item) {
  vec bytes;
  for (int i = 0; i < item.size(); i++) {
      bytes.push_back(item.at(i));
  }
  return bytes;
}
  
  
string pack109::deserialize_string(vec bytes) {
  if (bytes.size() < 2) {
    throw;
  }
  string item = "";
  if (bytes[0] == PACK109_S8) {
    int size = bytes[1];
    for (int i = 0; i < size; i++) {
      item += bytes[i+2];
    }
    return item;
  } 
  else if (bytes[0] == PACK109_S16) {
    int size = bytes[1];
    for (int i = 0; i < size; i++) {
      item += bytes[i+2];
    }
    return item;
  }
  else {
    throw;
  }
}

vec pack109::serialize(std::vector<u8> item) {
  vec bytes;
  bytes.push_back(PACK109_A8);
  for (int i = 0; i < item.size(); i++) {
    bytes.push_back(item[i]);
  }
  return bytes;
}

vec pack109::serialize(std::vector<u64> item) {
  vec bytes ;
  bytes.push_back(PACK109_A8);
  for (int i = 0; i < item.size(); i = i + 1) {
    vec item2 = serialize2( (u64) item[i]);
    for (int y = 0; y < item2.size (); y = y + 1) {
      bytes.push_back( (u8) item2[y]);
    }
  }
  return bytes;
}

vec pack109::serialize(std::vector<f64> item) {
  vec bytes;
  bytes.push_back(PACK109_A8);
  for (int i = 0; i < item.size(); i++) {
    bytes.push_back(item[i]);
  }
  return bytes;
}

vec pack109::serialize(std::vector<string> item) {
  vec bytes ;
  bytes.push_back(PACK109_A8);
  for (int i = 0; i <item.size(); i=i+1) {
    vec item2 = serialize2(item[i]);
    for (int y = 0; y < item2.size (); y = y+1) {
      bytes.push_back ((u8)item2[y]);
    }
  }
  return bytes;
}

std::vector<u8> pack109::deserialize_vec_u8(vec bytes) {
  if (bytes[0] == PACK109_A8) {
    //bytes.push_back(PACK109_A8);
    size_t size = bytes[1];
    std::vector<u8> x(bytes.size());
    for (int i = 0; i < 4; i++) {
      x[i] = bytes[i];
    }
      return x;
  }
}

std::vector<u64> pack109::deserialize_vec_u64(vec bytes) {
  if (bytes[0] == PACK109_A8) {
    size_t size = bytes[1];
    std::vector<u64> x(size);
    for (int i = 0; i < size; i++) {
      x[i] = bytes[i+2];
    }
    return x;
  }
}

std::vector<f64> pack109::deserialize_vec_f64(vec bytes) {
  if (bytes[0] == PACK109_A8) {
    size_t size = bytes[1];
    std::vector<f64> x(size);
    for (int i = 0; i < size; i++) {
      x[i] = bytes[i+2];
    }
    return x;
  }
}

std::vector<string> pack109::deserialize_vec_string(vec bytes) {
  if (bytes[0] == PACK109_A8) {
    size_t size = bytes[1];
    std::vector<string> x(size);
    for (int i = 0; i < size; i++) {
      x[i] = bytes[i+2];
    }
    return x;
  }
}

vec pack109::serialize(struct Person item) {
  vec age = serialize(item.age);
  vec height = serialize(item.height);
  vec name = serialize(item.name);
  vec all = age;
  all.insert(all.end(), height.begin(), height.end());
  all.insert(all.end(), name.begin(), name.end());
  return all;
}

struct Person pack109::deserialize_person(vec bytes) {
  for (int i = 0; i < bytes.size(); i++) {
    if (i = 0) {
      u8 age = deserialize_u8(bytes);
    }
    else if (i = 1) {
      f32 height = deserialize_f32(bytes);
    }
    else if (i = 2) {
      string name = deserialize_string(bytes);
    }
  }
}
  