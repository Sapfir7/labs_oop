#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <mutex>
#include <shared_mutex>
#include "observer.h"
#include "visitor.h"
#include "task.h"

enum class NpcType {
    Unknown = 0,
    ElfType = 1,
    DragonType = 2,
    DruidType = 3
};

struct NPC : public std::enable_shared_from_this<NPC> {
    NpcType type;
    std::string name;
    int x;
    int y;
    int move_distance;
    int kill_distance;
    bool alive;

    NPC(NpcType type, const std::string& name, int x, int y);
    virtual ~NPC() = default;

    virtual void accept(Visitor& visitor, std::shared_ptr<NPC> other) = 0;

    void addObserver(std::shared_ptr<Observer> observer);
    void notify(const std::string& event);

    bool isClose(const std::shared_ptr<NPC>& other, size_t distance) const;

    virtual void print() const;

    Task run(); // Метод запуска корутины для NPC

    virtual void save(std::ostream& os) const;
    static std::shared_ptr<NPC> load(std::istream& is);

private:
    std::vector<std::weak_ptr<Observer>> observers;
};

#endif