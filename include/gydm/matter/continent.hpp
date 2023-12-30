#pragma once

#include "../matter.hpp"
#include "../physics/color/rgba.hpp"
#include "../physics/geometry/aabox.hpp"
#include "../virtualization/screen.hpp"
#include "../forward.hpp"

namespace GYDM {
	class Continent : public GYDM::IMatter {
	public:
		virtual ~Continent() noexcept;
		
		Continent(GYDM::IPlane* planet, const GYDM::RGBA& background = transparent);
		Continent(GYDM::IPlane* planet, float width, float height = 0.0F, const GYDM::RGBA& background = transparent);

		const char* name() override;

	public:
		void construct(SDL_Renderer* renderer) override;
		GYDM::Box get_bounding_box() override;
		int update(uint64_t count, uint32_t interval, uint64_t uptime) override;
		void draw(SDL_Renderer* renderer, float x, float y, float Width, float Height) override;

	public:
		void set_background_color(const GYDM::RGBA& color);
		void set_border_color(const GYDM::RGBA& color);

    public: // low-level events
        bool on_pointer_pressed(uint8_t button, float local_x, float local_y, uint8_t clicks) override;
        bool on_pointer_move(uint32_t state, float local_x, float local_y, float dx, float dy, bool bye) override;
        bool on_pointer_released(uint8_t button, float local_x, float local_y, uint8_t clicks) override;

	public:
		template<typename P> P* unsafe_plane() { return static_cast<P*>(this->plane); }

	private:
		GYDM::IPlane* plane;

	private:
		GYDM::IScreen* screen;
		GYDM::RGBA background;
		GYDM::RGBA border;
		float width;
		float height;
	};
}
