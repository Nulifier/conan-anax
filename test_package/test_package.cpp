#include <cstdlib>
#include <anax/anax.hpp>

struct PositionComponent : anax::Component {
    float x;
    float y;
};

struct MovementSystem : anax::System<anax::Requires<PositionComponent>> {
    void update() {
        for (const anax::Entity& e : getEntities()) {
            PositionComponent& c = e.getComponent<PositionComponent>();
            c.x += 1.0f;
        }
    }
};

int main()
{
    // Create a world
    anax::World world;
    MovementSystem system;

    world.addSystem(system);

    anax::Entity entity = world.createEntity();
    entity.addComponent<PositionComponent>();
    entity.activate();

    world.refresh();

    system.update();

    return EXIT_SUCCESS;
}
