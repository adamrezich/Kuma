#pragma once

#include <unordered_map>
#include <string>
#include "Constants.h"

namespace Kuma
{
  class Allocator
  {
  private:
    struct Block
    {
      bool unused = true;
      void *data;
      Block *next;
    };
    struct Page
    {
      size_t blockSize;
      Block *head = nullptr;
      Page *next = nullptr;
    };

  public:
    struct Unit
    {
      Page *head = nullptr;
      size_t pageCount = 0;
      size_t blocksPerPage = 0;
      size_t blockSize = 0;
      std::string name;

      Unit() : name("__UNDEFINED__") {}

      void Setup(const char *name_, size_t blockSize_, size_t blocksPerPage_);
      void *operator [](size_t index);
    };

  private:
    Unit systemComponents[Constants::MaximumSystemComponents];
    size_t systemComponentCount = 0;

  public:
    Allocator() {}
    Unit *DefineSystemComponent(const char *name, size_t blockSize, size_t blocksPerPage);
  };
}
