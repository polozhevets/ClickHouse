#include <Processors/Executors/PipelineExecutor.h>

namespace DB
{

bool PipelineExecutor::TaskQueue::push(ExecutionState * value)
{
    std::lock_guard lock(mutex);
    container.push(value);
    return true;
}

bool PipelineExecutor::TaskQueue::pop(ExecutionState *& value)
{
    std::lock_guard lock(mutex);

    if (container.empty())
        return false;

    value = container.top();
    container.pop();
    return true;
}

void PipelineExecutor::TaskQueue::reserve(size_t)
{
    //container.reserve(size);
}

void PipelineExecutor::TaskQueue::reserve_unsafe(size_t)
{
    //container.reserve_unsafe(size);
}

}
