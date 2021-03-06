#pragma once
#include <new>

#include "Allocator.hpp"
#include "Framework/Interface/IRuntimeModule.h"

#ifndef ALIGN
#define ALIGN(x, a)         (((x) + ((a) - 1)) & ~((a) - 1))
#endif

namespace Engine
{
	class MemoryManager : public IRuntimeModule
	{
	public:
		template<typename T, typename... TArg>
		T* New(TArg... parameters)
		{
			return new (Allocate(sizeof(T))) T(parameters...);
		}
		template<typename T>
		void Delete(T* p)
		{
			p->~T();
			Free(reinterpret_cast<void*>(p), sizeof(T));
		}
	public:
		virtual ~MemoryManager() {}
		virtual int Initialize() override;
		virtual void Finalize() override;
		virtual void Tick() override;
		void* Allocate(size_t size);
		void* Allocate(size_t size, size_t alignment);
		void  Free(void* p, size_t size);

	private:
		inline static size_t* p_block_size_lookup_ = nullptr;
		inline static Allocator* p_allocator_ = nullptr;
	private:
		static Allocator* LookupAlloctor(size_t size);
	};
}