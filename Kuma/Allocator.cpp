#include "stdafx.h"
#include "Allocator.h"

namespace Kuma
{
  void *Allocator::Unit::operator [](size_t index)
  {
    Page *page = head;
    if (index < 1 || page == nullptr)
      throw "Invalid index";
    while (index > blocksPerPage)
    {
      index -= blocksPerPage;
      if (page->next == nullptr)
      {
        throw "Invalid index";
        break;
      }
      page = page->next;
    }
    Block *block = reinterpret_cast<Block *>(reinterpret_cast<unsigned char *>(page->head) + page->blockSize * index);
    if (block->unused)
      return nullptr;
    return block->data;
  }

  Allocator::Unit *Allocator::AddSystemComponent(const char *name, size_t blockSize, size_t blocksPerPage)
  {
    systemComponents[systemComponentCount] = Unit(name, blockSize, blocksPerPage);
    return &systemComponents[systemComponentCount++];
  }
}