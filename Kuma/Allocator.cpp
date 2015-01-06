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

  void Allocator::Unit::Setup(const char *name_, size_t blockSize_, size_t blocksPerPage_)
  {
    name = name_;
    blockSize = blockSize_;
    blocksPerPage = blocksPerPage_;
  }

  Allocator::Unit *Allocator::DefineSystemComponent(const char *name, size_t blockSize, size_t blocksPerPage)
  {
    systemComponents[systemComponentCount].Setup(name, blockSize, blocksPerPage);
    return &systemComponents[systemComponentCount++];
  }

}